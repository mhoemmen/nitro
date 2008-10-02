/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

package nitf;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.List;

import junit.framework.TestCase;
import nitf.TRE.FieldPair;

import org.apache.commons.lang.exception.ExceptionUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * This TestCase assumes your NITF_PLUGIN_PATH environment variable is set and
 * that the JITCID TRE plug-in exists.
 * 
 */
public class TRETest extends TestCase
{
    private static final Log log = LogFactory.getLog(TRETest.class);

    private TRE makeNewTRE(String tag) throws NITFException
    {
        return new TRE(tag, tag);
    }

    public void testCreate()
    {
        try
        {
            TRE tre = makeNewTRE("JITCID");
            assertEquals("JITCID", tre.getTag());
        }
        catch (NITFException e)
        {
            fail(ExceptionUtils.getStackTrace(e));
        }
    }

    public void testGetSetFields()
    {
        try
        {
            TRE tre = makeNewTRE("JITCID");
            String comment = "A comment";
            assertTrue(tre.setField("FILCMT", comment.getBytes()));
            Field field = tre.getField("FILCMT");
            assertNotNull(field);
            assertEquals(comment, field.getStringData().trim());
        }
        catch (NITFException e)
        {
            fail(ExceptionUtils.getStackTrace(e));
        }
    }

    public void testFind()
    {
        try
        {
            TRE tre = makeNewTRE("JITCID");
            List<FieldPair> fields = tre.find("FILCMT");
            assertNotNull(fields);
            assertEquals(1, fields.size());
            for (FieldPair fieldPair : fields)
            {
                log.info(fieldPair.getName());
            }
        }
        catch (NITFException e)
        {
            fail(ExceptionUtils.getStackTrace(e));
        }
    }

    public void testIterator()
    {
        try
        {
            TRE tre = makeNewTRE("JITCID");
            for (Iterator<FieldPair> it = tre.iterator(); it.hasNext();)
            {
                FieldPair pair = (FieldPair) it.next();
                log.info(pair.getName());
            }
        }
        catch (NITFException e)
        {
            fail(ExceptionUtils.getStackTrace(e));
        }
    }

    public void testPrint()
    {
        try
        {
            TRE tre = makeNewTRE("JITCID");
            tre.setField("FILCMT", "comment1".getBytes());
            //tre.setField("FILCMT", "comment2".getBytes());

            ByteArrayOutputStream out = new ByteArrayOutputStream();
            tre.print(new PrintStream(out));
            log.info(out.toString());
        }
        catch (NITFException e)
        {
            fail(ExceptionUtils.getStackTrace(e));
        }
    }
}
